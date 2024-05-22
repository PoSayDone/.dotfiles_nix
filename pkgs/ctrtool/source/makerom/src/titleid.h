#pragma once

typedef enum
{
	PID_BAD_RSF_SET = -1,
	PID_INVALID_CATEGORY = -2,
	PID_INVALID_UNIQUE_ID = -3,
	PID_INVALID_VARIATION = -4,
} Pid_Errors;

typedef enum
{
	PROGRAM_ID_CATEGORY_FLAG_NORMAL                         = 0x0000,     
	PROGRAM_ID_CATEGORY_FLAG_DLP_CHILD                      = 0x0001,      
	PROGRAM_ID_CATEGORY_FLAG_DEMO                           = 0x0002,        
	PROGRAM_ID_CATEGORY_FLAG_CONTENTS                       = 0x0003,        
	PROGRAM_ID_CATEGORY_FLAG_ADD_ON_CONTENTS                = 0x0004, 
	PROGRAM_ID_CATEGORY_FLAG_PATCH                          = 0x0006, 
	PROGRAM_ID_CATEGORY_FLAG_CANNOT_EXECUTION               = 0x0008, 
	PROGRAM_ID_CATEGORY_FLAG_SYSTEM                         = 0x0010, 
	PROGRAM_ID_CATEGORY_FLAG_REQUIRE_BATCH_UPDATE           = 0x0020, 
	PROGRAM_ID_CATEGORY_FLAG_NOT_REQUIRE_USER_APPROVAL      = 0x0040, 
	PROGRAM_ID_CATEGORY_FLAG_NOT_REQUIRE_RIGHT_FOR_MOUNT    = 0x0080, 
	PROGRAM_ID_CATEGORY_FLAG_CAN_SKIP_CONVERT_JUMP_ID       = 0x0100,
	PROGRAM_ID_CATEGORY_FLAG_TWL                            = 0x8000,
} ProgramIdCategoryFlag;

typedef enum
{
	PROGRAM_ID_CATEGORY_APPLICATION         = ( PROGRAM_ID_CATEGORY_FLAG_NORMAL ),

	PROGRAM_ID_CATEGORY_DLP_CHILD           = ( PROGRAM_ID_CATEGORY_FLAG_DLP_CHILD ),

	PROGRAM_ID_CATEGORY_DEMO                = ( PROGRAM_ID_CATEGORY_FLAG_DEMO ),

	PROGRAM_ID_CATEGORY_CONTENTS            = ( PROGRAM_ID_CATEGORY_FLAG_CONTENTS ),

	PROGRAM_ID_CATEGORY_PATCH               = ( PROGRAM_ID_CATEGORY_FLAG_CANNOT_EXECUTION
												| PROGRAM_ID_CATEGORY_FLAG_PATCH),

	PROGRAM_ID_CATEGORY_ADD_ON_CONTENTS     = ( PROGRAM_ID_CATEGORY_FLAG_ADD_ON_CONTENTS
												| PROGRAM_ID_CATEGORY_FLAG_CANNOT_EXECUTION
												| PROGRAM_ID_CATEGORY_FLAG_NOT_REQUIRE_RIGHT_FOR_MOUNT ),

	PROGRAM_ID_CATEGORY_FIRMWARE            = ( PROGRAM_ID_CATEGORY_FLAG_NORMAL
												| PROGRAM_ID_CATEGORY_FLAG_CANNOT_EXECUTION
												| PROGRAM_ID_CATEGORY_FLAG_SYSTEM
												| PROGRAM_ID_CATEGORY_FLAG_REQUIRE_BATCH_UPDATE
												| PROGRAM_ID_CATEGORY_FLAG_CAN_SKIP_CONVERT_JUMP_ID ),


	PROGRAM_ID_CATEGORY_BASE                = ( PROGRAM_ID_CATEGORY_FLAG_NORMAL
												| PROGRAM_ID_CATEGORY_FLAG_SYSTEM
												| PROGRAM_ID_CATEGORY_FLAG_REQUIRE_BATCH_UPDATE
												| PROGRAM_ID_CATEGORY_FLAG_CAN_SKIP_CONVERT_JUMP_ID ),


	PROGRAM_ID_CATEGORY_APPLET              = ( PROGRAM_ID_CATEGORY_FLAG_NORMAL
												| PROGRAM_ID_CATEGORY_FLAG_SYSTEM
												| PROGRAM_ID_CATEGORY_FLAG_REQUIRE_BATCH_UPDATE ),


	PROGRAM_ID_CATEGORY_SYSTEM_APPLICATION  = ( PROGRAM_ID_CATEGORY_FLAG_NORMAL
												| PROGRAM_ID_CATEGORY_FLAG_SYSTEM ),


	PROGRAM_ID_CATEGORY_SYSTEM_CONTENT      = ( PROGRAM_ID_CATEGORY_FLAG_CONTENTS
												| PROGRAM_ID_CATEGORY_FLAG_CANNOT_EXECUTION
												| PROGRAM_ID_CATEGORY_FLAG_SYSTEM ),


	PROGRAM_ID_CATEGORY_SHARED_CONTENT      = ( PROGRAM_ID_CATEGORY_FLAG_CONTENTS
												| PROGRAM_ID_CATEGORY_FLAG_CANNOT_EXECUTION
												| PROGRAM_ID_CATEGORY_FLAG_SYSTEM
												| PROGRAM_ID_CATEGORY_FLAG_NOT_REQUIRE_RIGHT_FOR_MOUNT ),


	PROGRAM_ID_CATEGORY_AUTO_UPDATE_CONTENT = ( PROGRAM_ID_CATEGORY_FLAG_CONTENTS
												| PROGRAM_ID_CATEGORY_FLAG_CANNOT_EXECUTION
												| PROGRAM_ID_CATEGORY_FLAG_SYSTEM
												| PROGRAM_ID_CATEGORY_FLAG_NOT_REQUIRE_USER_APPROVAL
												| PROGRAM_ID_CATEGORY_FLAG_NOT_REQUIRE_RIGHT_FOR_MOUNT ),

} ProgramIdCategory;

u64 ConvertTwlIdToCtrId(u64 pgid);

int GetProgramID(u64 *dest, rsf_settings *rsf, bool IsForExheader);
int GetUniqueID(u32 *dest, rsf_settings *rsf);

u16 GetTidCategory(u64 titleId);
u32 GetTidUniqueId(u64 titleId);

bool IsDemo(u16 Category);
bool IsSystem(u16 Category);
bool IsDlpChild(u16 Category);
bool IsPatch(u16 Category);
bool IsContents(u16 Category);
bool IsAddOnContent(u16 Category);
