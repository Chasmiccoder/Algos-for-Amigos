function toBinary(string) {
    const codeUnits = new Uint16Array(string.length);
    for (let i = 0; i < codeUnits.length; i++) {
      codeUnits[i] = string.charCodeAt(i);
    }
    const charCodes = new Uint8Array(codeUnits.buffer);
    let result = '';
    for (let i = 0; i < charCodes.byteLength; i++) {
      result += String.fromCharCode(charCodes[i]);
    }
    return result;
  }
  
function encrypt(){
    plain = document.forms["enc"]["plain"].value
    bstring = toBinary(plain)
    cipher = btoa(bstring)
    console.log(cipher)
    document.getElementById('output-box').innerHTML = cipher
    document.getElementById('output-box').style.visibility = "visible"
}

function decrypt(){
    cipher = document.forms["dec"]["cipher"].value
    plain = atob(cipher)
    console.log(plain)
    document.getElementById('output-box').innerHTML = plain
    document.getElementById('output-box').style.visibility = "visible"
}

function showEnc(){
    console.log("E")
    location.reload()
    document.getElementById("decrypt").style.visibility = "hidden"; 
    document.getElementById("encrypt").style.visibility = "visible";
    document.getElementById('output-box').style.visibility = "hidden"
    return false;
}

function showDec(){
    console.log("D")
    document.getElementById("encrypt").style.visibility = "hidden"; 
    document.getElementById("decrypt").style.visibility = "visible";
    document.getElementById('output-box').style.visibility = "hidden"
    return false;  
}