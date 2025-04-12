import React from "react";

const Child = ({ message }) => {
  return <p>Message from parent: {message}</p>;
};

const Parent = () => {
  return <Child message="Hey there! Props are working!" />;
};

export default Parent;
