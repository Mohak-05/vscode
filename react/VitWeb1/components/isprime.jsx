export const Pr = () => {
  const num = 13;
  let c = 0;
  for (let i = 2; i < num; i++) {
    if (num % i == 0) {
      c = 1;
      break;
    }
  }
  return <h1>is number prime:{c == 1 ? "No" : "Yes"}</h1>;
};
