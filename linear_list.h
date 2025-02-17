/**
 * 線形リストを扱うライブラリです。 
 * ただし、いくつかの機能のために安全性を捨てているため、
 * 理解して使わないと、意図せぬ動作が引き起こされます。
 * 
 * また、このライブラリはマクロの呼び出しのみを想定しているため、
 * 直接使われたくない関数の名前には先頭にdo_not_useが付きます。 
 */
#pragma once

void* do_not_use_list_get_last(void* list,unsigned int size);
void* do_not_use_list_create(unsigned int size,void* next,void* pre);
void do_not_use_list_release(void* list,unsigned int size);
void do_not_use_list_push(void* list,const void* const data,unsigned int size);
void do_not_use_list_deleate(void* itr,unsigned int size);

/*
 *  LINEAR_LIST_NEXT(list)
 * 
 *  listの次の要素のイテレーターを返します、型はリストと同様です。
 *　次の要素がない場合返り値はNULLです
*/
#define LINEAR_LIST_NEXT(list) ((typeof(list))(*(void**)((void*)list + sizeof(typeof(*list)))))

/*
 *  LINEAR_LIST_PREV(list)
 * 
 *  listの前の要素のイテレーターを返します、型はリストと同様です。
 *  前の要素がない場合返り値はNULLです
*/
#define LINEAR_LIST_PREV(list) ((typeof(list))(*(void**)((void*)list +sizeof(typeof(*list))+sizeof(void*))))


/*
 *  LINEAR_LIST_CREATE(type)
 * 
 *  typeで指定された型の空のリストを返します。
 *  返されるリストは type*型です
*/
#define LINEAR_LIST_CREATE(type) ((type*)do_not_use_list_create(sizeof(type),(void*)0,(void*)0))

/*
 *  LINEAR_LIST_RELEASE(list)
 * 
 *  listを開放します
*/
#define LINEAR_LIST_RELEASE(list) do_not_use_list_release(list,sizeof(typeof(*list)))

/*
 *  LINEAR_LIST_PUSH(list,data)
 * 
 *  listにdataをPUSHします。
 *　dataはLINEAR_LIST_CREATEで指定した方と同じ必要があります
*/
#define LINEAR_LIST_PUSH(list,data) do_not_use_list_push(list,&data,sizeof(typeof(*list)))

/*
 *  LINEAR_LIST_ERASE(itr)
 * 
 *  listからitrの要素を削除します。
*/
#define LINEAR_LIST_ERASE(itr) do_not_use_list_deleate(itr,sizeof(typeof(*itr)));


/*
 *  LINEAR_LIST_LAST(list)
 * 
 *  listの最後の要素を取得します。
 *　型はlistと同様です
*/
#define LINEAR_LIST_LAST(list) ((typeof(list))do_not_use_list_get_last(list,sizeof(typeof(*list))))

/*
 *  LINEAR_LIST_FOREACH(list,iter)
 * 
 *  listの全ての要素をiterに入れて次のコードブロックを実行します。
 *　for文のヘッダと同じです。
*/
#define LINEAR_LIST_FOREACH(list,iter) for(iter = *(void**)(((void*)list) + sizeof(*list));iter != NULL;iter = LINEAR_LIST_NEXT(iter))

/*
 *  LINEAR_LIST_FOREACH_R(list,iter)
 * 
 *  LINEAR_LIST_FOREACHと同様ですが、代入は後ろから始まります。
*/
#define LINEAR_LIST_FOREACH_R(list,iter) for(iter = LINEAR_LIST_LAST(list);iter != list;iter = LINEAR_LIST_PREV(iter))
