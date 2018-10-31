USE [Room]
GO
/****** Object:  Table [dbo].[RenderingLink]    Script Date: 10/31/2018 14:01:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[RenderingLink](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[parentrenderingid] [int] NOT NULL,
	[childrenderingid] [int] NOT NULL,
 CONSTRAINT [PK_RenderingLink] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Space]    Script Date: 10/31/2018 14:01:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Space](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[x] [float] NOT NULL,
	[y] [float] NOT NULL,
	[z] [float] NOT NULL,
	[description] [varchar](50) NULL,
 CONSTRAINT [PK_Space] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[SceneRenderingLink]    Script Date: 10/31/2018 14:01:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SceneRenderingLink](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[sceneid] [int] NOT NULL,
	[renderingid] [int] NOT NULL,
 CONSTRAINT [PK_SceneRenderings] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Scene]    Script Date: 10/31/2018 14:01:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Scene](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[name] [varchar](50) NOT NULL,
 CONSTRAINT [PK_Scene] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Rendering]    Script Date: 10/31/2018 14:01:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Rendering](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[renderingtypeid] [int] NOT NULL,
	[spaceid] [int] NOT NULL,
	[renderinglinkid] [int] NOT NULL,
	[datasource] [varchar](50) NULL,
 CONSTRAINT [PK_Rendering] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[RenderingType]    Script Date: 10/31/2018 14:01:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[RenderingType](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[name] [varchar](50) NOT NULL,
	[handler] [varchar](50) NULL,
 CONSTRAINT [PK_RenderingType] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
/****** Object:  ForeignKey [FK_Rendering_RenderingLink]    Script Date: 10/31/2018 14:01:22 ******/
ALTER TABLE [dbo].[Rendering]  WITH CHECK ADD  CONSTRAINT [FK_Rendering_RenderingLink] FOREIGN KEY([renderinglinkid])
REFERENCES [dbo].[RenderingLink] ([id])
GO
ALTER TABLE [dbo].[Rendering] CHECK CONSTRAINT [FK_Rendering_RenderingLink]
GO
/****** Object:  ForeignKey [FK_Rendering_RenderingType]    Script Date: 10/31/2018 14:01:22 ******/
ALTER TABLE [dbo].[Rendering]  WITH CHECK ADD  CONSTRAINT [FK_Rendering_RenderingType] FOREIGN KEY([renderingtypeid])
REFERENCES [dbo].[RenderingType] ([id])
GO
ALTER TABLE [dbo].[Rendering] CHECK CONSTRAINT [FK_Rendering_RenderingType]
GO
/****** Object:  ForeignKey [FK_Rendering_Space]    Script Date: 10/31/2018 14:01:22 ******/
ALTER TABLE [dbo].[Rendering]  WITH CHECK ADD  CONSTRAINT [FK_Rendering_Space] FOREIGN KEY([spaceid])
REFERENCES [dbo].[Space] ([id])
GO
ALTER TABLE [dbo].[Rendering] CHECK CONSTRAINT [FK_Rendering_Space]
GO
/****** Object:  ForeignKey [FK_RenderingLink_ChildRendering]    Script Date: 10/31/2018 14:01:22 ******/
ALTER TABLE [dbo].[RenderingLink]  WITH CHECK ADD  CONSTRAINT [FK_RenderingLink_ChildRendering] FOREIGN KEY([childrenderingid])
REFERENCES [dbo].[Rendering] ([id])
GO
ALTER TABLE [dbo].[RenderingLink] CHECK CONSTRAINT [FK_RenderingLink_ChildRendering]
GO
/****** Object:  ForeignKey [FK_RenderingLink_ParentRendering]    Script Date: 10/31/2018 14:01:22 ******/
ALTER TABLE [dbo].[RenderingLink]  WITH CHECK ADD  CONSTRAINT [FK_RenderingLink_ParentRendering] FOREIGN KEY([parentrenderingid])
REFERENCES [dbo].[Rendering] ([id])
GO
ALTER TABLE [dbo].[RenderingLink] CHECK CONSTRAINT [FK_RenderingLink_ParentRendering]
GO
/****** Object:  ForeignKey [FK_SceneRendering_Scene]    Script Date: 10/31/2018 14:01:22 ******/
ALTER TABLE [dbo].[SceneRenderingLink]  WITH CHECK ADD  CONSTRAINT [FK_SceneRendering_Scene] FOREIGN KEY([sceneid])
REFERENCES [dbo].[Scene] ([id])
GO
ALTER TABLE [dbo].[SceneRenderingLink] CHECK CONSTRAINT [FK_SceneRendering_Scene]
GO
/****** Object:  ForeignKey [FK_SceneRenderingLink_Rendering]    Script Date: 10/31/2018 14:01:22 ******/
ALTER TABLE [dbo].[SceneRenderingLink]  WITH CHECK ADD  CONSTRAINT [FK_SceneRenderingLink_Rendering] FOREIGN KEY([renderingid])
REFERENCES [dbo].[Rendering] ([id])
GO
ALTER TABLE [dbo].[SceneRenderingLink] CHECK CONSTRAINT [FK_SceneRenderingLink_Rendering]
GO
