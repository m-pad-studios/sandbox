FROM node:12

# Create app directory
WORKDIR C:\Users\mpark\Desktop\whatabyte-portal

COPY package*.json ./

RUN npm install

COPY . .

EXPOSE 8080
CMD ["node", "index.js"]