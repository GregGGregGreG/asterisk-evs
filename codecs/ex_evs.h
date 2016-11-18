#include "asterisk/format_cache.h"      /* for ast_format_evs */
#include "asterisk/frame.h"             /* for ast_frame, etc */

static uint8_t ex_evs[] = { /* PRIMARY_16400, WB */
	0x05, 0x51, 0x63, 0x4e, 0xa7, 0x87, 0x0c, 0xc4,
	0x50, 0x3c, 0xcf, 0x60, 0x19, 0xbf, 0xd3, 0x93,
	0xf4, 0xd9, 0x49, 0xac, 0x89, 0xce, 0x4c, 0x4d,
	0x5e, 0x01, 0xff, 0x80, 0x00, 0x17, 0x17, 0xd5,
	0x73, 0x7b, 0xd5, 0x1d, 0xe1, 0xcf, 0x65, 0x0b,
	0xee, 0x95
};

static struct ast_frame *evs_sample(void)
{
	static struct ast_frame f = {
		.frametype = AST_FRAME_VOICE,
		.datalen = sizeof(ex_evs),
		.samples = 320,
		.mallocd = 0,
		.offset = 0,
		.src = __PRETTY_FUNCTION__,
		.data.ptr = ex_evs,
	};

	f.subclass.format = ast_format_evs;

	return &f;
}
