import React, { Component } from "react";

export class UG extends Component {
  render() {
    return (
      <h2>
        Hello, {this.props.firstName} {this.props.lastName}!
      </h2>
    );
  }
}
