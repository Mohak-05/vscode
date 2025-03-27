import { useState } from "react";

export const Rs = () => {
  const [text, setText] = useState("");

  const reversed = text.split("").reverse().join("");
  const isPalindrome = text === reversed ? "Palindrome" : "Not Palindrome";

  return (
    <div>
      <input
        type="text"
        placeholder="Enter text"
        value={text}
        onChange={(e) => setText(e.target.value)}
      />
      <p>
        {reversed} - {isPalindrome}
      </p>
    </div>
  );
};
