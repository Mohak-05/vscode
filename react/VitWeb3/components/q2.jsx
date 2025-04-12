import React from "react";

const InlineButton = () => {
  const btnStyle = {
    backgroundColor: "skyblue",
    padding: "10px 20px",
    fontSize: "16px",
    border: "none",
    borderRadius: "5px",
  };

  return <button style={btnStyle}>Inline Styled Button</button>;
};

export default InlineButton;
