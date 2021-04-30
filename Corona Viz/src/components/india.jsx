import React, { Component } from 'react';
import Tracker from './Tracker';
import Hov from './Hover';

class App extends Component {
  render() {
    return (
      <div>
        <Tracker/>
        <Hov/>
      </div>
    );
  }
}

export default App;
