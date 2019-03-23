#include "socket.h"
#include <qDebug>
Socket::Socket()
{

}
void  Socket::readMessage()
{

       QDataStream in(this->tcpSocket);
        // 设置数据流版本，这里要和服务器端相同
        in.setVersion(QDataStream::Qt_5_5);
       // 如果是刚开始接收数据
        if (bufSize == 0) {
            //判断接收的数据是否大于两字节，也就是文件的大小信息所占的空间
            //如果是则保存到blockSize变量中，否则直接返回，继续接收数据
            if(this->tcpSocket->bytesAvailable() < (int)sizeof(quint16)) return;  //bytesAvailable()返回字节数
            in >> bufSize;
        }
        // 如果没有得到全部的数据，则返回，继续接收数据
        if(this->tcpSocket->bytesAvailable() < bufSize) return;
        // 将接收到的数据存放到变量中
        in >> message;

        qDebug()<<"客户端接受到信息："<<message;
        // 显示接收到的数据*/

}
void Socket::sendMessage(QString msg)
{
    //数据包 ：数据的大小信息+实际数据
    QByteArray buf;
    //用于读写二进制数据  优点：严格定义数据流的类型和每个类型的长度
    // 不用关心编码之间的转换问题
    QDataStream out (&buf,QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_5);

    out << (quint16)0;//quint16 的大小 （两字节） 用于存放数据大小信息的

    out <<msg;

    out.device()->seek(0);//返回起始位置

    out << (quint16)(buf.size() - sizeof(quint16));

    //获取已经建立的套接字
    this->tcpSocket->write(buf);

    qDebug()<<"客户端发送了信息："<<msg;
}
void Socket::newConnect()
{
    bufSize = 0;
    this->tcpSocket->abort();//取消已有连接
    //stcpSocket->connectToHost("10.25.49.107",1234);
    this->tcpSocket->connectToHost("localhost", 1234);
    qDebug()<<"客户端建立了连接";
}
QTcpSocket * Socket::getTcpSocket()
{
    return this->tcpSocket;
}
void Socket::setTcpSocket(QTcpSocket *tcp)
{
   this->tcpSocket=tcp;
}
