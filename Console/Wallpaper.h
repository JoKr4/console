#pragma once

#include "MainFrame.h"


class MyThread
{
public:
                            MyThread                            (void);
  virtual                  ~MyThread                            (void);

  void                      Start                               (DWORD dwStackSize = 0);
  DWORD                     Stop                                (DWORD dwTimeout);
  virtual DWORD             Process                             (HANDLE hStopSignal) = 0;

private:
  static unsigned int __stdcall myThreadFunction(void*);

private:
  std::unique_ptr<void, CloseHandleHelper> hStopSignalPtr;
  std::unique_ptr<void, CloseHandleHelper> hThreadPtr;
  DWORD                                    dwResult;

};


class WallPaperThread : public MyThread
{
  MainFrame&                               m_mainFrame;

public:
                            WallPaperThread                     (MainFrame& mainFrame):m_mainFrame(mainFrame) {}
  virtual                  ~WallPaperThread                     (void) {}

  virtual DWORD             Process                             (HANDLE hStopSignal);
};
