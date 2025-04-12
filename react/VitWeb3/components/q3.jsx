import React from "react";

const InternalButton = () => {
  return (
    <>
      <style>{`
        .internal-btn {
          background-color: lightgreen;
          padding: 10px 20px;
          font-size: 16px;
          border: none;
          border-radius: 5px;
        }
      `}</style>
      <button className="internal-btn">Internal Styled Button</button>
    </>
  );
};

export default InternalButton;
