// HACK: Because these are partial headers, i.e. rpcndr.h depends on other headers
// which we do not distribute, we need to define these ourselves:
#define _Maybenull_
#define _Pre_maybenull_
#define _Post_invalid_
#define __in
#define __out
#define _In_
#define _Out_
#define _Out_opt_
#define _Ret_notnull_
#define _Inout_
#define _Outptr_opt_
#define _In_range_(lb, ub)
#define _Out_writes_z_(size)
#define _Use_decl_annotations_
#define _Out_writes_(size)
#define _In_opt_count_(size)
#define _Outptr_result_maybenull_
#define _Analysis_assume_(expr)
#define _Field_size_full_(size)
#define _In_reads_bytes_(size)
#define _Field_size_opt_(size)
#define _In_NLS_string_(size)
#define _Outptr_
