import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class Server {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			System.out.println("Waiting for Client: ...");
			ServerSocket ss = new ServerSocket(9806);
			Socket soc = ss.accept();
			System.out.println("Client Connected...");
			BufferedReader in = new BufferedReader(new InputStreamReader(soc.getInputStream()));

			System.out.println("Client message Recived . \nMessage is: " + in.readLine());

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
