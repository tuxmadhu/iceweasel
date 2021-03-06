// Return seek.ogv file content for the first request with a given key.
// All subsequent requests return a redirect to a different-origin resource.
function handleRequest(request, response)
{
  var key = request.queryString.match(/^key=(.*)$/);

  if (getState(key[1]) == "redirect") {
    var origin = request.host == "localhost" ? "example.org" : "localhost:8888";
    response.setStatusLine(request.httpVersion, 303, "See Other");
    response.setHeader("Location", "http://" + origin + "/tests/content/media/video/test/seek.ogv");
    response.setHeader("Content-Type", "text/html");
    return;
  }

  setState(key[1], "redirect");

  var file = Components.classes["@mozilla.org/file/directory_service;1"].
                        getService(Components.interfaces.nsIProperties).
                        get("CurWorkD", Components.interfaces.nsILocalFile);
  var fis  = Components.classes['@mozilla.org/network/file-input-stream;1'].
                        createInstance(Components.interfaces.nsIFileInputStream);
  var bis  = Components.classes["@mozilla.org/binaryinputstream;1"].
                        createInstance(Components.interfaces.nsIBinaryInputStream);
  var paths = "tests/content/media/video/test/seek.ogv";
  var split = paths.split("/");
  for(var i = 0; i < split.length; ++i) {
    file.append(split[i]);
  }
  fis.init(file, -1, -1, false);
  dump("file=" + file + "\n");
  bis.setInputStream(fis);
  var bytes = bis.readBytes(bis.available());
  response.setStatusLine(request.httpVersion, 206, "Partial Content");
  response.setHeader("Content-Range", "bytes 0-" + (bytes.length - 1) + "/" + bytes.length);
  response.setHeader("Content-Length", ""+bytes.length, false);
  response.setHeader("Content-Type", "video/ogg", false);
  response.write(bytes, bytes.length);
  bis.close();
}
