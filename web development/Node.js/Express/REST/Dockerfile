FROM node:latest
WORKDIR /usr/src/app
COPY . .
RUN npm install
EXPOSE 80
ENTRYPOINT ["node","app.js"]
