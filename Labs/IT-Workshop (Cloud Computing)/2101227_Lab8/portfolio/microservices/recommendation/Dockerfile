# Use an official Node.js runtime as the base image
FROM node:latest

# Set the working directory within the container
WORKDIR /usr/src/service3

# Copy the package.json and package-lock.json files to the working directory
COPY package*.json ./

# Install application dependencies
RUN npm install

# Copy all source code to the working directory
COPY . .

# Expose a port that your application will listen on
EXPOSE 5003

# Define the command to start your Node.js application
CMD [ "node", "app3.js" ]
