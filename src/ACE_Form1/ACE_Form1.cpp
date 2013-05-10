// ACE_Form1.cpp : 기본 프로젝트 파일입니다.

#include "ace/ace.h"
#include "ace/Log_Msg.h"
#include "ace/streams.h"


ACE_OSTREAM_TYPE* m_output=0;
int StartLog();
void CloseLog();

int ACE_TMAIN (int, ACE_TCHAR *[])
{
	StartLog();
	ACE::init();

	ACE_DEBUG ((LM_INFO, ACE_TEXT("ACE_Form1 Start\n")));


	ACE::fini();

	return EXIT_SUCCESS;
}


int StartLog()
{
	int a=0;
	const ACE_TCHAR *program = ACE_TEXT("..\\..\\logs\\ACE_Form1.txt");
	m_output = (ACE_OSTREAM_TYPE *) new ofstream(program);  
	if(m_output==0)
		 ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("%p\n"), ACE_TEXT ("new ofstream failed")), -1); \
	ACE_LOG_MSG->msg_ostream (m_output, 0); 
	ACE_LOG_MSG->set_flags (ACE_Log_Msg::OSTREAM);
	ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("(%P|%t) Starting %s test at %D\n"), program));
}

void CloseLog()
{
	ACE_LOG_MSG->clr_flags (ACE_Log_Msg::OSTREAM); 
	delete m_output;
	m_output=0;
}