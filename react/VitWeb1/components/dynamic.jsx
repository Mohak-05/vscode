export const Dyn = () => {
  const d = new Date();
  let v = d.getDay();
  const days = [
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
  ];
  return <h1>day of the week: {days[v]}</h1>;
};
