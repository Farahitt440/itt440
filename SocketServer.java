import java.net.*;
import java.io.*;

public class SocketServer extends Thread
{	private ServerSocket serverSocket;
	public SocketServer (int port) throws IOException
	{	serverSocket = new ServerSocket(port);
		serverSocket.setSoTimeout(10000);
	}
	public void run()
	{	while(true)
		{	try
			{	System.out.println("Waiting for client on port"+serverSocket.getLocalPort()+"...");

				Socket server = serverSocket.accept();
				System.out.println("Just connected to"+server.getRemoteSocketAddress());

				DataInputStream in = newDataInputStream(server.getInputStream());
				System.out.println(in.readUTF());

				DataOutputStream out = new DataOutputStream(server.getOutputStream());
				out.writeUTF("Thank you for connecting to"+server.getLocalSocketAddress()+"\Goodbye");

				server.close();
			}catch(IOException e)
			{	e.printStackTrace();
				break;
			}
		}
	}

	public static void main(String []args)
	{	int port=Integer.parseInt(args[0]);
		try
		{	Thread t = new SocketServer (port);
			t.start();
		}
		catch(IOException e)
		{	e.printStackTace()l
		}
	}
}
