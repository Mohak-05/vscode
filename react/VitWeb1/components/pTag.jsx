export const PTag = () => {
  const num1 = 3;
  const num2 = 4;
  return (
    <>
      <p>
        the numbers {num1},{num2}:
        <br />
        {num1 * num1 + num2 * num2}
      </p>
    </>
  );
};
