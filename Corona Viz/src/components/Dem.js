import * as React from 'react';
import logosd from './logo.png';
import {Link} from 'react-router-dom';
import {
  Chart,
  BarSeries,
  ArgumentAxis,
  ValueAxis,
} from '@devexpress/dx-react-chart-bootstrap4';
import '@devexpress/dx-react-chart-bootstrap4/dist/dx-react-chart-bootstrap4.css';
import { EventTracker, HoverState, SelectionState } from '@devexpress/dx-react-chart';
import logo from './load.gif'

console.log(logosd);
const data = [
  { conuntry: 'United States', population: 712184 },
  { conuntry: 'Spain', population: 191726 },
  { conuntry: 'Italy', population: 	172434 },
  { conuntry: 'Germany', population: 141399 },
  { conuntry: 'France', population: 109252 },
  { conuntry: 'United Kingdom', population: 108692 },
  { conuntry: 'India', population: 14793 },
];

const compare = (
  { series, point }, { series: targetSeries, point: targetPoint },
) => series === targetSeries && point === targetPoint;

export default class Demo extends React.PureComponent {
  
  constructor(props) {
    super(props);

    this.state = {
      data,
      selection: [],
      hover: undefined,
    };

    this.click = ({ targets }) => {
      const target = targets[0];
      if (target) {
        this.setState(({ selection }) => ({
          selection: selection[0] && compare(selection[0], target) ? [] : [target],
        }));
      
      }
    };
    this.changeHover = hover => this.setState({ hover });
  }

  render() {
    const { data: chartData, selection , hover } = this.state;
    require('../assets/css/home.css')
    return (
      <div className="fullwidthbanner-container" length="10000">
      <div >
        <span>
        <br></br><br></br>
          Corona count:
          {' '}
          {selection.length ? data[selection[0].point].population : undefined}
        </span>
        <div className="card">
          <Chart width="700" data={chartData}>
            <ArgumentAxis />
            <ValueAxis />

            <BarSeries
              valueField="population"
              argumentField="conuntry"
            />
            <EventTracker onClick={this.click} />
            <SelectionState selection={selection} />
            <HoverState hover={hover} onHoverChange={this.changeHover} />
          </Chart>
        </div>
      </div><center>
      <br></br>
      <h3 >
      <Link to="/india">India survey</Link>
      </h3>
      <br></br>
      <img src={logo} alt="Corona Tracker" /><br></br><br></br><br></br>
      </center>
      
      </div>
    );
  }
}
