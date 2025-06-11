from .model import GPT
from .dataset import NameDataset
from .trainer import Trainer, TrainerConfig

import torch
import random
random.seed(0)

def initialize_vanilla_model(mconf):
    # Instantiated the model with the provided configuration
    attention_model = GPT(mconf)
    
    return attention_model

def initialize_perceiver_model(mconf, bottleneck_dim=32):
    # Modified the configuration for perceiver by defining the bottleneck dimensions
    mconf.bottleneck_dim = bottleneck_dim
    
    # Instantiated the model with the modified configuration
    attention_model = GPT(mconf)
    
    return attention_model

def finetune(reading_params_path, finetune_corpus_path, pretrain_dataset, block_size, model, finetune_lr=6e-4, writer=None):
    if reading_params_path is not None:
        model.load_state_dict(torch.load(reading_params_path, map_location=torch.device('cpu')))

    tconf = TrainerConfig(max_epochs=10, batch_size=256, learning_rate=finetune_lr,
                          lr_decay=True, warmup_tokens=512*20, final_tokens=200*len(pretrain_dataset)*block_size,
                          num_workers=2)

    trainer_obj = Trainer(model, pretrain_dataset, None, tconf)
    trainer_obj.train()

    return tconf, trainer_obj

def evaluate(model, val_dataset, loss_fn):
    model.eval()  # sets model to eval mode (this deactivates dropout, batch norm etc.)
    total_loss = 0.0
    total_steps = 0
    
    # don't need to track gradients here b/c we won't be doing backprop during eval
    with torch.no_grad():
        for batch in val_dataset:
            output = model(batch)  # forward pass
            # your loss might look different depending on your problem
            loss = loss_fn(output, batch)
            total_loss += loss.item()
            total_steps += 1

    model.train()  # sets model back to train mode

    return total_loss / total_steps  # returning average loss across all steps
def pretrain(pretrain_dataset, block_size, model, pretrain_lr=6e-3, writer=None, val_dataset=None, writing_params_path='model_state.pt'):
    tconf = TrainerConfig(max_epochs=650, batch_size=128, learning_rate=pretrain_lr,
                          lr_decay=True, warmup_tokens=512*20, final_tokens=200*len(pretrain_dataset)*block_size,
                          num_workers=2)  # Reduced num_workers from 4 to 2

    trainer_obj = Trainer(model, pretrain_dataset, None, tconf)
    
    if val_dataset is not None:
        best_val_loss = float('inf')
        for epoch in range(tconf.max_epochs):
            trainer_obj.train()
            val_loss = evaluate(val_dataset)  # You need to implement or integrate this `evaluate` function, that returns the validation loss
            if val_loss < best_val_loss:
                best_val_loss = val_loss
                torch.save(model.state_dict(), writing_params_path)  # Save the best performing model
    else:
        trainer_obj.train()  # If no validation dataset is provided, proceed with the original training process

    return tconf, trainer_obj

def train(model, writing_params_path, trainer_obj):
    torch.save(model.state_dict(), writing_params_path)
    return writing_params_path
