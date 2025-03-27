import React from "react";

const UserPosts = () => {
  const posts = [
    "Just learned React! It's awesome!",
    "Working on a new project using JavaScript.",
    "Excited to explore full-stack development!",
  ];

  return (
    <div className="user-posts">
      <h3>Recent Posts</h3>
      {posts.map((post, index) => (
        <div key={index} className="post">
          <p>{post}</p>
        </div>
      ))}
    </div>
  );
};

export default UserPosts;
