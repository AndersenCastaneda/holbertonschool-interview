#!/usr/bin/node
// Prints all characters of a Star Wars movie

const request = require('request');
const movieID = process.argv[2];

if (movieID) {
  const url = `https://swapi-api.hbtn.io/api/films/${movieID}`;
  request(url, function taskCompleted (err, response, body) {
    if (!err) {
      const characters = JSON.parse(body).characters;
      const list = [];
      for (const character of characters) {
        list.push(new Promise((resolve, reject) =>
          request(character, function (err, response, body) {
            if (err) {
              reject(err);
            }
            const names = JSON.parse(body).name;
            resolve(names);
          })));
      }
      Promise.all(list).then((names) => names.forEach((name) => console.log(name)));
    }
  });
}
