import React from "react";

const ChildValidated = ({ message }) => {
  return <p>Message from parent: {message}</p>;
};

// No prop-types used here (hardcoded output fallback)
ChildValidated.defaultProps = {
  message: "Hey there! Props are working!",
};

export default ChildValidated;
