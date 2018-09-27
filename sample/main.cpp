#include <webrtc/api/peerconnectioninterface.h>
#include <webrtc/base/ssladapter.h>
#include <webrtc/base/thread.h>

#ifdef WIN32
#include <webrtc/base/win32socketinit.h>
#include <webrtc/base/win32socketserver.h>
#include <Windows.h>
#endif

int main(int argc, char **argv) {
#ifdef WIN32
  rtc::EnsureWinsockInit();
  rtc::Win32SocketServer w32_ss;
  rtc::Win32Thread w32_thread(&w32_ss);
  rtc::ThreadManager::Instance()->SetCurrentThread(&w32_thread);
#endif

  rtc::InitializeSSL();
  rtc::InitRandom(rtc::Time());
  rtc::ThreadManager::Instance()->WrapCurrentThread();

  rtc::Thread *signalingThread = new rtc::Thread();
  rtc::Thread *workerThread = new rtc::Thread();

  signalingThread->SetName("signaling_thread", NULL);
  workerThread->SetName("worker_thread", NULL);

  if (!signalingThread->Start() || !workerThread->Start()) {
    return 1;
  }

  rtc::scoped_refptr<webrtc::PeerConnectionFactoryInterface> pcFactory =
      webrtc::CreatePeerConnectionFactory(signalingThread,
                                          workerThread,
                                          NULL, NULL, NULL);

  pcFactory = NULL;

  if (rtc::ThreadManager::Instance()->CurrentThread() == signalingThread) {
    rtc::ThreadManager::Instance()->SetCurrentThread(NULL);
  }

  signalingThread->Stop();
  workerThread->Stop();

  delete signalingThread;
  delete workerThread;

  rtc::CleanupSSL();
  return 0;
}