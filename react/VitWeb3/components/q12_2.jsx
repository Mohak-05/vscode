
import React, { useRef, useState } from "react";

const FormUseRef = () => {
  const nameRef = useRef();
  const emailRef = useRef();
  const [output, setOutput] = useState("");

  const handleSubmit = (e) => {
    e.preventDefault();
    const name = nameRef.current.value;
    const email = emailRef.current.value;
    setOutput(`Name: ${name} | Email: ${email}`);
  };

  return (
    <div>
      <h2>Form using useRef</h2>
      <form onSubmit={handleSubmit}>
        <input type="text" placeholder="Name" ref={nameRef} />
        <br />
        <input type="email" placeholder="Email" ref={emailRef} />
        <br />
        <button type="submit">Submit</button>
      </form>
      <p>{output}</p>
    </div>
  );
};

export default FormUseRef;
