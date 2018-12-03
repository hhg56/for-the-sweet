#pragma once
const ULONG MAX_SAMPLE_COUNT = 50;

class CGameTimer
{
private:
	bool m_bHardwareHasPerformanceCounter;		// ��ǻ�Ͱ� Performance Counter�� ������ �ִ°�
	float m_fTimeScale;							// Scale Counter�� ��
	float m_fTimeElapsed;						// ������ ������ ���� ������ �ð�
	__int64 m_nCurrentTime;						// ������ �ð�
	__int64 m_nLastTime;						// ������ �������� �ð�
	__int64 m_nPerformancFrequency;				// ��ǻ���� Performance Frequency
	
	float m_fFrameTime[MAX_SAMPLE_COUNT];		// ������ �ð��� �����ϱ� ���� �迭
	ULONG m_nSampleCount;						// ������ ������ Ƚ��

	unsigned long m_nCurrentFrameRate;			// ������ ������ Rate
	unsigned long m_nFramesPerSecond;			// �ʴ� ������ ��
	float m_fFPSTimeElapsed;					// ������ Rate ��� �ҿ� �ð�

public:
	CGameTimer();
	virtual ~CGameTimer();

	void Tick(float fLockFPS = 0.0f);											// Ÿ�̸��� �ð��� �����Ѵ�.
	void Reset();																// ����?

	unsigned long GetFrameRate(LPTSTR lpszString = NULL, int nCharactoers = 0);	// ������ ����Ʈ�� ��ȯ�Ѵ�.
	float GetTimeElpased();														// �������� ��� ��� �ð��� ��ȯ�Ѵ�.
};

