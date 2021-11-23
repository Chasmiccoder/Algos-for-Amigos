function hex_to_ascii() {
    let hex = document.getElementById("inputnum").value;
    let h = hex.toString();
    var str = '';
    for (var n = 0; n < h.length; n += 2) {
        str += String.fromCharCode(parseInt(hex.substr(n, 2), 16));
    }
    console.log(str);
    document.getElementById("output").value = str;
}

function ascii_to_hex() {

    var str=document.getElementById("output").value;
    var arr1 = [];
    for (var n = 0; n < str.length; n++) {
        var hex = Number(str.charCodeAt(n)).toString(16);
        arr1.push(hex);
    }
    var final= arr1.join('');
    document.getElementById("inputnum").value=final;

}

function reload() {
    document.getElementById("myapp").reset();
}