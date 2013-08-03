#include "etk.h"
#include "etk_type.h"
#include "etk_rect.h"
#include "etk_window.h"
#include "etk_widget.h"
#include "etk_wnd_manager.h"
#include "etk_image_bmp_decoder.h"
#include "etk_image_jpeg_decoder.h"
#include "etk_canvas_ex.h"


int main(int argc, char* argv[]){
	EtkWndManager *manager;
	EtkBitmap *b;
	EtkRect t;
	EtkWidget* desktop;
	EtkWidget* hellowin;
	EtkImageDecoder *bmp_decoder;
	
	//��ʼ������etk ����
	etk_init(argc, argv);

	//ȡ�ô��ڹ���
	manager=etk_get_wnd_manager();
	//����ͼƬ jpeg���� ,Ҳ������bmp ���Ǻ�����Ҫ�ĳ� etk_image_jpeg_decoder_create();
	bmp_decoder=etk_image_bmp_decoder_create();

	//��������

	desktop=etk_create_window(0,0,639,479,ETK_WIDGET_DESKTOP|ETK_WIDGET_NO_BITMAP);
	b=bmp_decoder->decode(bmp_decoder,"bg.bmp");
	t.x=0;t.y=0;
	t.width=b->w;
	t.height=b->h;
	etk_canvas_set_bitmap(desktop->canvas,b);
	
	//��������
	hellowin=etk_create_window(250,200,300,200,ETK_WIDGET_WINDOW);
	
	//�����ַ� hello world �����ڻ�����ȥ
	etk_canvas_draw_string(hellowin->canvas,100,100,"hello,world.");
	etk_canvas_fill_circle(hellowin->canvas,80,90,60,GRAY);
	etk_canvas_draw_circle(hellowin->canvas,156,67,20,BLUE);

	//���
	etk_temhum_create(10,50,200,290);
	etk_light_create(100,100,250,180);
	etk_power_create(300,200,250,180);
	etk_status_create(200,100,200,150);
	etk_ajust_create(300,300,200,150);
	//��ʾ���д���
	etk_widget_show_all(desktop);

	//����etk
	etk_run();
	//�˳�etk
	etk_exit();

	return 0;
}
