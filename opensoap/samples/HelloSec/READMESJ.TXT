HelloSec �T���v��
=================


[1] �T�v: 

  ���̃f�B���N�g���ɂ́AOpenSOAP �̃Z�L�����e�B�@�\�̎g�p���@����ю��s���
  �������Ƃ�ړI�Ƃ����V���v���� Web �T�[�r�X�̃T���v���v���O�����ł��� 
  HelloSec �T���v���̃T�[�r�X����уN���C�A���g�v���O�����ꎮ���܂܂�Ă��܂��B
  
  HelloSec Web �T�[�r�X�́AHello ���\�b�h�� MyName �p�����[�^�Ŏw�肳�ꂽ
  ��������󂯎��A"Hello (������)!"�� Reply �p�����[�^�Ƃ��ĕԂ��܂��B
  
  ���N�G�X�g����у��X�|���X���b�Z�[�W�́A�p�����[�^���Í������ꂽ��A
  �d�q�������t������đ��M����܂��B
  
  ��M���ꂽ���N�G�X�g����у��X�|���X���b�Z�[�W�́A���������؂��ꂽ��A
  �p�����[�^������������Ă��珈������܂��B
  
  ���ۂɑ���M����郊�N�G�X�g�^���X�|���X���b�Z�[�W�̗�́A
  hello_sec_request.xml ����сAhello_sec_response.xml ���Q�Ƃ��Ă��������B
  
  �Í����E����������я����t���E���؂Ɏg�p����錮�t�@�C���͈ȉ��̂Ƃ���ł��B
  
  ���t�@�C����              �Ӗ�
  ------------------------  --------------------
  privKey_HelloClient.pem   �N���C�A���g�̔閧��
  pubKey_HelloService.pem   �T�[�r�X�̌��J��    
  pubKey_HelloClient.pem    �N���C�A���g�̔閧��
  privKey_HelloService.pem  �T�[�r�X�̌��J��    

  �e���t�@�C���̋�̓I�Ȏg�����͈ȉ��̂Ƃ���ł��B

  �g�p���[�`��              �v���O����     �ړI      ���t�@�C����
  ------------------------  -------------  --------  ------------------------
  			    	        
  ���N�G�X�g���b�Z�[�W�쐬  �N���C�A���g   �Í���    pubKey_HelloService.pem
                                           �����t��  privKey_HelloClient.pem
  			    	        
  ���N�G�X�g���b�Z�[�W���  �T�[�r�X       ��������  pubKey_HelloClient.pem
                                           ������    privKey_HelloService.pem
			    	        
  ���X�|���X���b�Z�[�W�쐬  �T�[�r�X       �Í���    pubKey_HelloClient.pem
                                           �����t��  privKey_HelloService.pem
			    	        
  ���X�|���X���b�Z�[�W���  �N���C�A���g   ��������  pubKey_HelloService.pem
                                           ������    privKey_HelloClient.pem


[2] ���s�t�@�C���̍쐬:

  OpenSOAP API �C���X�g�[����́Amake clean �������ƂŁAmake -f HelloSec.mak 
  ���s���ĉ������B�ȉ��̃t�@�C�����쐬����܂��B
  
  * HelloSecClient
    HelloSec �N���C�A���g�v���O�����ł��B
  
  * HelloSecService
    �W�����o�͂�p���� HelloSec �T�[�r�X�v���O�����ł��B
  
  * HelloSecService.cgi
    CGI �^�� HelloSec �T�[�r�X�v���O�����ł��Bcgi �����s�\�ȃf�B���N�g����
    �u�����Ƃŗ��p�\�ƂȂ�܂��B


[3] �C���X�g�[��:

  �v���O�����t�@�C���A�ݒ�t�@�C���A�f�[�^�t�@�C�����͓K�؂ȏꏊ��
  �C���X�g�[������K�p������܂��B
  
  �����̎��s���ł́Amake -f HelloSec.mak install �œK�؂ȏꏊ��
  �C���X�g�[������܂��B
  
  �������Acgi �Ńv���O�������C���X�g�[������ꏊ�́Amake �t�@�C����
  CGI_BIN_DIR �ϐ��ɐݒ肵�Ă����K�p������܂��B
  
  HelloSec.mak �ŃC���X�g�[�������e�t�@�C���ƃC���X�g�[���ꏊ��
  �ȉ��̂Ƃ���ł��B
  
  �C���X�g�[�������t�@�C��  �C���X�g�[���ꏊ
  --------------------------  ---------------------------
  HelloSecService.cgi         /home/httpd/cgi-bin
  HelloSecService             /usr/local/opensoap/services
  HelloSec.ssml               /usr/local/opensoap/conf/ssml
  privKey_HelloService.pem    /usr/local/opensoap/services/HelloSec
  pubKey_HelloClient.pem      /usr/local/opensoap/services/HelloSec
  
  �ڂ����� HelloSec.mak �t�@�C�����Q�Ƃ��Ă��������B


[4] ���s:
  
  �T���v���̎��s�̎d�����́AHelloSec.mak �t�@�C�����Q�Ƃ��Ă��������B
  �t�@�C���̌㕔�Ɏ��s��Ƃ��ăe�X�g���s�p�̃��[�����L�q���Ă���܂��B
  
  ���Ƃ��΁A���[�� ctest �̏ꍇ�A�ȉ��̂悤�Ɏ��s���邱�Ƃ��ł��܂��B
  
  make -f HelloSec.mak ctest
  
  �e�X�g���s�p�̊e���[���̈Ӗ��͈ȉ��̂Ƃ���ł��B
  
  * stest (�T�[�r�X�P�̃e�X�g)
    �\�ߍ쐬���ꂽ���N�G�X�g���b�Z�[�W(�e�L�X�g�t�@�C��)�� CGI �ł̃T�[�r�X��
    ���͂��ăT�[�r�X�v���O�����̒P�̃e�X�g���s���܂��B
    
  * ctest (�N���C�A���g�E�T�[�r�X�A�g�e�X�g)
    �N���C�A���g���� CGI �ł̃T�[�r�X���Ăяo���e�X�g���s���܂��B
    
  * cstest (�N���C�A���g�E�T�[�o�E�T�[�r�X�A�g�e�X�g)
    �N���C�A���g���� OpensOAP �T�[�o���o�R���ĕW�����o�͔ł̃T�[�r�X���Ăяo��
    �e�X�g���s���܂��B
    ���s�ɂ��邽�߂ɂ́Aopensoap-server-ctl start �����s���� OpenSOAP �T�[�o��
    �N�����Ă����K�v������܂��B

