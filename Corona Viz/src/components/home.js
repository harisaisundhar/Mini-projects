import * as React from 'react';


export default class Demo extends React.PureComponent {


  render() {
    require('../assets/css/home.css')
    return (
        <div className="fullwidthbanner-container">
        <h1 className="introh centered">We are SoSweet!<br /><span className="subintroh lightblue">Handcrafted, responsive web design</span></h1>  
       </div>
    );
  }
}
