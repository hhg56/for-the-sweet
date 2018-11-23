#pragma once
#include "Timer.h"
class GameFramework
{
private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;

	int m_nWndClientWidth;
	int m_nWndClientHeight;
	//DXGI ���丮 �������̽��� ���� ������
	IDXGIFactory4 *m_pdxgiFactory;	

	//���� ü�� �������̽��� ���� �������̴�. �ַ� ���÷��� ���� ���� �ʿ�
	IDXGISwapChain3 *m_pdxgiSwapChain;

	//Direct3D ����̽� �������̽��� ���� �������̴�. �ַ� ���ҽ��� �����ϱ� ���Ͽ� �ʿ��ϴ�
	ID3D12Device *m_pd3dDevice;

	//MSAA ���� ���ø��� Ȱ��ȭ�ϰ� ���� ���ø� ������ �����Ѵ�.
	bool m_bMsaa4xEnable = false;
	UINT m_nMsaa4xQualityLevels = 0; 

	//����ü���� �ĸ� ������ ����
	static const UINT m_nSwapChainBuffers = 2;

	//���� ���� ü���� �ĸ� ���� �ε���
	UINT m_nSwapChainBufferIndex;

	//���� Ÿ�� ����, ������ �� �������̽� ������, ���� Ÿ�� ������ ������ ũ���̴�.
	ID3D12Resource *m_ppd3dRenderTargetBuffers[m_nSwapChainBuffers];
	ID3D12DescriptorHeap *m_pd3dRtvDescriptorHeap;
	UINT m_nRtvDescriptorIncrementSize;

	//����- ���׽� ����, ������ �� �������̽� ������, ����-���ٽ� ������ ������ ũ��
	ID3D12Resource *m_pd3dDepthStencilBuffer;
	ID3D12DescriptorHeap *m_pd3dDsvDescriptorHeap;
	UINT m_nDsvDescriptorIncrementSize;

	//��� ť, ��� �Ҵ���, ��� ����Ʈ, ���������ν�����Ʈ �������̽� ������, 
	ID3D12CommandQueue *m_pd3dCommandQueue;
	ID3D12CommandAllocator *m_pd3dCommandAllocator;
	ID3D12GraphicsCommandList *m_pd3dCommandList;
	ID3D12PipelineState *m_pd3dPipelineState;

	//�潺 �������̽� ������, �潺�� ��, �̺�Ʈ �ڵ�
	ID3D12Fence *m_pd3dFence;
	UINT64 m_nFenceValue;
	HANDLE m_hFenceEvent;

#if defined(_DEBUG)
	ID3D12Debug *m_pd3dDebugController;
#endif
	//����Ʈ, ���� �簢��
	D3D12_VIEWPORT m_d3dViewport;
	D3D12_RECT m_d3dScissorRect;

	//���� ������ ��ũ���� ����� Ÿ�̸�
	CGameTimer m_GameTimer;
	//������ ����Ʈ�� �� �������� ĸ�ǿ� ����ϱ� ���� ���ڿ�
	_TCHAR m_pszFrameRate[50];
public:
	GameFramework();
	~GameFramework();
	
	//�����ӿ�ũ�� �ʱ�ȭ�ϴ� �Լ��̴� (�� �����찡 �����Ǹ� ȣ��ȴ�)
	bool OnCreate(HINSTANCE hInstance, HWND hMainWnd);
	void OnDestroy();
	//������ ��üȭ��
	void OnResizeBackBuffers();

	//���� ü��, ����̽�, ������ ��, ��� ť/ �Ҵ���/ ����Ʈ�� �����ϴ� �Լ�
	void CreateSwapChain();
	void CreateDirect3DDevice();
	void CreateRtvAndDsvDescriptorHeaps();
	void CreateCommandQueueAndList();
	void CreateRenderTargetView();
	void CreateDepthStencilView();
	
	//�������� �޽��� ���� ��ÿ�� �����ϰ� �Ҹ��ϴ� �Լ��̴�.
	void BuildObjects();
	void ReleaseObjects();

	//�����ӿ�ũ�� �ٽ�(����� �Է�, �ִϸ��̼�, ������)�� �����ϴ� �Լ��̴�
	void ProcessInput();
	void AnimateObjects();
	void FrameAdvance();

	//CPU�� GPU�� ����ȭ�ϴ� �Լ�
	void WaitForGpuComplete();

	//�������� �޽���(Ű����, ���콺 �Է�)�� ó���ϴ� �Լ�
	void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK OnProcessingWindowMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

};

