import java.io.*;;
import java.net.*;
public class server
{
 public static void main(String[] args) throws Exception
{
 //Initialize Sockets
 while (true) {

    ServerSocket ssock = new ServerSocket(5000);
    Socket socket = ssock.accept();

    DataInputStream dis = new DataInputStream(socket.getInputStream());
    String str = dis.readUTF();
    if(str.equals(1)){
        break;
    }
    else{

        //The InetAddress specification
        InetAddress IA = InetAddress.getByName("localhost");
        byte[] contents = new byte[10000];
        //Initialize the FileOutputStream to the output file's full path.
        FileOutputStream fos = new FileOutputStream("receive.txt");
        //get the file as the buffered output streama
        BufferedOutputStream bos = new BufferedOutputStream(fos);
        InputStream is = socket.getInputStream();
        //No of bytes read in one read() call
        int bytesRead = 0;
        while((bytesRead=is.read(contents))!=-1)
        bos.write(contents, 0, bytesRead);
        System.out.println("File saved successfully!");
        //Specify the file
    
        bos.flush();
        socket.close();
        ssock.close();
    } 
}
}
}