import { useState } from "react";
import React from "react";
import { Hd } from "../components/header.jsx";
import { Rd } from "../components/random.jsx";
import "./App.css";

function App() {
  return (
    <>
      <Hd title="This is the header" />
      <Rd/>
    </>
  );
}

export default App;
