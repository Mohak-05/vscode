import React, { Component } from "react";
class LifeCycleDemo extends Component {
  constructor(props) {
    super(props);
    this.state = { count: 0 };
    console.log("LifeCycleDemo constructor called");
  }
  componentDidMount() {
    console.log("LifeCycleDemo component has mounted");
  }
  componentDidUpdate() {
    console.log("LifeCycleDemo: componentDidUpdate");
  }
  componentWillUnmount() {
    console.log("LifeCyleDemo : component will unmount");
  }

  increment = () => {
    this.setState({ count: this.state.count + 1 });
  };
  render() {
    return (
      <div className="lifecycleDemo">
        <h2>Life Cycle Demo</h2>
        <p>Count : {this.state.count}</p>
        <button onClick={this.increment}>Increment</button>
      </div>
    );
  }
}
export default LifeCycleDemo;
