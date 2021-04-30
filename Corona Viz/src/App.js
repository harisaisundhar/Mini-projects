import React, { Component } from 'react';
import india from './components/india';
import main from './components';
import err from './components/404';
import chk from './components/Pencil';

import {BrowserRouter as Router,Route,Switch,Redirect} from 'react-router-dom';

class App extends Component {
  render() {
    return <Router>
    <Switch>
      <Route exact path="/Vision-Corona-2020/" component={main}></Route>
      <Route exact path="/Vision-Corona-2020/india" component={india}></Route>
      <Route exact path="/Vision-Corona-2020/404" component={err}></Route>
      <Route exact path="/Vision-Corona-2020/check" component={chk}></Route>
      <Redirect to="/Vision-Corona-2020/404"></Redirect>
      </Switch>
    </Router>
  }
}

export default App;
