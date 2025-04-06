import { useState } from "react";

export const Tc = () => {
  const [temperature, setTemperature] = useState("");
  const [scale, setScale] = useState("C");

  const handleChange = (e) => {
    if (e.target.name === "temperature") {
      setTemperature(e.target.value);
    } else {
      setScale(e.target.value);
    }
  };

  const convertTemperature = () => {
    if (temperature === "" || isNaN(temperature)) return "";
    return scale === "C"
      ? ((temperature * 9) / 5 + 32).toFixed(2)
      : (((temperature - 32) * 5) / 9).toFixed(2);
  };

  return (
    <div>
      <h2>Temperature Converter</h2>
      <input
        type="text"
        name="temperature"
        placeholder="Enter temperature"
        value={temperature}
        onChange={handleChange}
      />
      <select name="scale" value={scale} onChange={handleChange}>
        <option value="C">Celsius</option>
        <option value="F">Fahrenheit</option>
      </select>
      <p>
        Converted Temperature: {convertTemperature()}
        {scale === "C" ? "F" : "C"}
        
      </p>
    </div>
  );
};
