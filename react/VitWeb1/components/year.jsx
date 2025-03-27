import { useState } from "react";

export const LYck = () => {
  const [year, setYear] = useState("");

  const isLeapYear = (year) => {
    return (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0;
  };

  return (
    <div>
      <input
        type="number"
        placeholder="Enter year"
        value={year}
        onChange={(e) => setYear(e.target.value)}
      />
      <p>{year && (isLeapYear(year) ? "Leap Year" : "Not a Leap Year")}</p>
    </div>
  );
};
