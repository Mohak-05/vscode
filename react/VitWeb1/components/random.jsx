import { useState } from "react";

export const Rn = () => {
  const [num, setNum] = useState(null);

  return (
    <div>
      <button onClick={() => setNum(Math.floor(Math.random() * 100) + 1)}>
        Generate Random Number
      </button>
      <p>{num !== null ? num : "Click the button!"}</p>
    </div>
  );
};
