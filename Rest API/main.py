#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb  2 09:36:10 2020

@author: harisai
"""
import uuid 
import pathlib
import os
from app import app
from flask import Flask, request, redirect, jsonify, send_file, json
from werkzeug.utils import secure_filename

p={
   "id":"",
   "file_name":""
   }

iid=[]
fid=[]

ALLOWED_EXTENSIONS = set(['txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif', 'mp4', 'mp3'])
currentDirectory = pathlib.Path(app.config['UPLOAD_FOLDER'])

def allowed_file(filename):
	return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS


@app.route('/files/<id>',methods=['DELETE'])
def delete_files(id):
    try:
#        filename = secure_filename(file.filename)
        for x in range(len(iid)):
            if str(id) == str(iid[x]):
                filename=fid[x]
                mn=iid[x]
                fid.remove(fid[x])
                iid.remove(iid[x])
                path = os.path.join(app.config['UPLOAD_FOLDER'], filename) 
                os.remove(path)
                resp = jsonify({"object "+mn+" deleted successfully"})
                #te = "object "+mn+" deleted successfully"
                resp.status_code = 200
                return resp
        resp = jsonify({'error' : 'File does not exist'})
        resp.status_code = 404
        return resp
    
    except Exception as e:
        resp = jsonify({'error' : 'File does not exist'})
        resp.status_code = 404
        return resp
        return str(e)

@app.route('/files/list',methods=['GET'])
def list_files():
    files=[]
    for x in range(len(fid)):  
        p["file_name"]=fid[x]
        p["id"]=iid[x]
        files.append(p)
    return json.dumps(files)

@app.route('/files/<id>',methods=['GET'])
def get_file(id):
    try:
        if len(iid)<=0:
            resp = jsonify({'error' : 'No data present'})
            resp.status_code = 409
            return resp
        resp = jsonify({'message' : 'The File gets downloaded'})
        resp.status_code = 200
        for x in range(len(iid)):
            if str(id) == str(iid[x]):
                filename=fid[x]
                resp.status_code = 200
                return send_file(os.path.join(app.config['UPLOAD_FOLDER'], filename))
                resp = jsonify({'data sent'})
                return resp
        resp = jsonify({'error' : 'File not found'})
        resp.status_code = 409
        #return json.dumps(iid)
        return json.dumps({ "error": 'File does not exist' }), 404
    except Exception as e:
        return str(e)

@app.route('/files', methods=['PUT'])
def upload_file():
    flag=0
    if 'file' not in request.files:
        resp = jsonify({'message' : 'No file part in the request'})
        resp.status_code = 400
        return resp
    file = request.files['file']
    if file.filename == '':
        resp = jsonify({'message' : 'No file selected for uploading'})
        resp.status_code = 400
        return resp
    if file and allowed_file(file.filename):
        filename = secure_filename(file.filename)
        for j in range(len(fid)):
            if str(filename)==str(fid[j]):
                flag=1
        if flag==1:
            resp = jsonify({'error' : 'Duplicate file'})
            resp.status_code = 409
            return resp
        file.save(os.path.join(app.config['UPLOAD_FOLDER'], filename))
        fid.append(filename)
        temp=uuid.uuid1()
        iid.append(temp)
        
        resp = jsonify(temp)
        resp.status_code = 200
        return resp
    else:
        resp = jsonify({'message' : 'Allowed file types are txt, pdf, png, jpg, jpeg, gif'})
        resp.status_code = 400
        return resp

if __name__ == "__main__":
    with open('config.json') as f:
        data = json.load(f)
    n=data['node_count']
    for i in range(1,n):
        open('/Users/harisai/uploads/node%s' % i, 'w').write("")
    app.run(debug=True)