import { useState } from "react";

export const Newlogin = () => {
  const [formData, setFormData] = useState({
    username: "",
    password: "",
    city: "",
    server: "",
    role: "",
    signOn: [],
  });

  const handleChange = (e) => {
    const { name, value, type, checked } = e.target;

    if (type === "checkbox") {
      setFormData((prev) => ({
        ...prev,
        signOn: checked
          ? [...prev.signOn, value]
          : prev.signOn.filter((item) => item !== value),
      }));
    } else {
      setFormData((prev) => ({
        ...prev,
        [name]: value,
      }));
    }
  };

  const handleReset = () => {
    setFormData({
      username: "",
      password: "",
      city: "",
      server: "",
      role: "",
      signOn: [],
    });
  };

  return (
    <div
      style={{
        fontFamily: "Arial",
        width: "350px",
        margin: "auto",
        textAlign: "left",
        border: "1px solid black",
        padding: "20px",
        borderRadius: "8px",
      }}
    >
      <h2 style={{ textAlign: "center" }}>form input</h2>
      <form>
        <div style={{ marginBottom: "10px" }}>
          <label>Username: </label>
          <input
            type="text"
            name="username"
            value={formData.username}
            onChange={handleChange}
            style={{ width: "100%" }}
          />
        </div>
        <div style={{ marginBottom: "10px" }}>
          <label>Password: </label>
          <input
            type="password"
            name="password"
            value={formData.password}
            onChange={handleChange}
            style={{ width: "100%" }}
          />
        </div>
        <div style={{ marginBottom: "10px" }}>
          <label>City of Employment: </label>
          <input
            type="text"
            name="city"
            value={formData.city}
            onChange={handleChange}
            style={{ width: "100%" }}
          />
        </div>
        <div style={{ marginBottom: "10px" }}>
          <label>Web server: </label>
          <select
            name="server"
            value={formData.server}
            onChange={handleChange}
            style={{ width: "100%" }}
          >
            <option value="">-- Choose a server --</option>
            <option value="Server1">Server 1</option>
            <option value="Server2">Server 2</option>
            <option value="Server3">Server 3</option>
          </select>
        </div>
        <div style={{ marginBottom: "10px" }}>
          <label>Please specify your role:</label>
          <div>
            <input
              type="radio"
              name="role"
              value="Admin"
              onChange={handleChange}
            />{" "}
            Admin
            <input
              type="radio"
              name="role"
              value="Engineer"
              onChange={handleChange}
            />{" "}
            Engineer
            <input
              type="radio"
              name="role"
              value="Manager"
              onChange={handleChange}
            />{" "}
            Manager
            <input
              type="radio"
              name="role"
              value="Guest"
              onChange={handleChange}
            />{" "}
            Guest
          </div>
        </div>
        <div style={{ marginBottom: "10px" }}>
          <label>Single Sign-on to the following:</label>
          <div>
            <input
              type="checkbox"
              name="signOn"
              value="Mail"
              onChange={handleChange}
            />{" "}
            Mail
            <input
              type="checkbox"
              name="signOn"
              value="Payroll"
              onChange={handleChange}
            />{" "}
            Payroll
            <input
              type="checkbox"
              name="signOn"
              value="Self-service"
              onChange={handleChange}
            />{" "}
            Self-service
          </div>
        </div>
        <div style={{ textAlign: "center" }}>
          <button type="button" style={{ marginRight: "10px" }}>
            Login
          </button>
          <button type="button" onClick={handleReset}>
            Reset
          </button>
        </div>
      </form>
    </div>
  );
};
