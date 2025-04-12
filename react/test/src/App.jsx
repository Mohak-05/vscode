import React, { useState } from "react";
import "./App.css";
// import { Head } from "../components/header.jsx";

// in header.jsx:
// export const Head = () => {
//   var v = 69;
//   return (
//     <>
//       <h1>{v}</h1>
//     </>
//   );
// };

function Header() {
  return <header className="header">My App Header</header>;
}

function Navbar() {
  return (
    <nav className="navbar">
      <a href="#">Home</a>
      <a href="#">About</a>
      <a href="#">Contact</a>
    </nav>
  );
}

function Footer() {
  return <footer className="footer">© 2025 My App</footer>;
}

function Body() {
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");

  const validatePassword = (pwd) => {
    const digitCount = (pwd.match(/\d/g) || []).length;
    if (pwd.length < 5) return "Password must be at least 5 characters";
    if (digitCount < 3) return "Password must contain at least 3 digits";
    return "";
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    const validationError = validatePassword(password);
    setError(validationError);
    if (!validationError) {
      alert("Form submitted!");
    }
  };

  return (
    <main className="body">
      <form onSubmit={handleSubmit} className="form">
        <h2 className="form-title">Password Form</h2>
        <label htmlFor="password" className="label">
          Password
        </label>
        <input
          type="password"
          id="password"
          placeholder="Enter password"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
          className="input"
        />
        {error && <p className="error">{error}</p>}
        <button type="submit" className="submit-btn">
          Submit
        </button>
      </form>
    </main>
  );
}

export default function App() {
  return (
    <div className="app-container">
      <Header />
      <Navbar />
      <Body />
      <Footer />
    </div>
  );
}
