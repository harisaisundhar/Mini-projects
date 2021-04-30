import React from 'react';
import {Link} from 'react-router-dom';
class Tracker extends React.Component {

    render() {
        require('../assets/css/err.css')
        return (
            <div>
            <nav className="shelf">
              <a className="book home-page"><Link to="/">Home Page</Link></a>
              <a className="book about-us"><Link to="/india">India Survey</Link></a>
              <a className="book contact"><a href="https://harisaisundhar.github.io/portfolio/">Contact</a></a>
           
              <span className="book not-found" />
              <span className="door left" />
              <span className="door right" />
            </nav>
            <h1>Error 404</h1>
            <p>The page you're loking for can't be found</p>
          </div>
          );
    }
}

export default Tracker;
