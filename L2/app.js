var express = require('express');
var app = express();
var path = require('path');
var fs = require('fs');
var bd = require('body-parser');

app.use(bd.json());
app.use(express.static('static'));
app.use(express.static('file'));

app.get('/', function (req, res) {
	res.sendFile(__dirname + '/static/html/hack.txt');
});

app.get('/hack',function (req,res) {
    res.sendFile(__dirname +'/static/html/index.html');
});


app.get('/hack_correct',function (req,res) {
    fs.readFile(__dirname+'/static/html/hack.txt', 'utf8', function(err, data) {
        if (err) {

            console.log('Could not find or open file for reading\n');
        } else {
            res.writeHead(200, {
                'Content-Type':
                    'text/html'
            });

            res.end(data);
        }
    })
});

app.post('/write', function (req,res) {
    var path = __dirname+'/file/post.txt';

    fs.writeFile(path,JSON.stringify(req.body), function(err){
        if (err){
        	console.log(err);
        	res.send("error");
        }
        else
        {
        	res.send("success write");
        }
    });
});
   
var server = app.listen(8080, function () {
	var host = server.address().address;
	var port = server.address().port;
	console.log('Example app listening at http://%s:%s',host, port);
});			