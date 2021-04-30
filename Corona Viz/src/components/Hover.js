import _ from 'lodash';
import React from 'react';
import createClass from 'create-react-class';
import { BarChart, Legend, chartConstants } from 'lucid-ui';

const data = [
  { x: 'Delhi',  deaths: 72, cases: 1707, recovered: 42 },
  { x: 'Maharashtra',  deaths: 331, cases: 1707, recovered: 201 },
  { x: 'Madhya Pradesh',  deaths: 69, cases: 1355,recovered: 69 },
  { x: 'Telengana',  deaths: 186, cases: 791, recovered: 18 },
  { x: 'Tamil Nadu', deaths: 283, cases: 1323, recovered: 15 },
];
const yAxisFields = ['deaths', 'cases', 'recovered'];
const palette = chartConstants.PALETTE_7;

const style = {
  paddingTop: '10rem',
};

export default createClass({
  render() {
    return (
      
      <div style={style}>
        <BarChart
          width={750}
          data={data}
          yAxisFields={yAxisFields}
          yAxisMin={0}
          yAxisTitle='Corona Count'
          palette={palette}
        />

        <Legend style={{ verticalAlign: 'top' }}>
          {_.map(yAxisFields, (field, i) => (
            <Legend.Item
              key={field}
              hasPoint
              color={palette[i % palette.length]}
            >
              {field}
            </Legend.Item>
          ))}
        </Legend>
      </div>
    );
  },
});