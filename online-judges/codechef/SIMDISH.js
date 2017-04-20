process.stdin.resume();
process.stdin.setEncoding('utf8');

var main = function () {
  for(var tc = 1; tc < lines[0]*2; tc += 2) {
    var a = lines[tc].split(' ');
    var b = lines[tc+1].split(' ');

    var matches = 0;
    for(var i=0; i<4; i++) {
      for(var j=0; j<4; j++) {
        if(a[i] === b[j]) matches++;
      }
    }
    var ans = (matches >= 2) ? 'similar' : 'dissimilar';
    console.log(ans);
  }
};

var chunks = '';

process.stdin.on('data', function(data) {
    chunks += data;
});
    
process.stdin.on('end', function () {
  lines = chunks.split("\n");
  main();
  process.exit();
});
