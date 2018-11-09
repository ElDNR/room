using System;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata;

namespace room.server.data.Models
{
    public partial class RoomContext : DbContext
    {
        public RoomContext()
        {
        }

        public RoomContext(DbContextOptions<RoomContext> options)
            : base(options)
        {
        }

        public virtual DbSet<Rendering> Rendering { get; set; }
        public virtual DbSet<RenderingLink> RenderingLink { get; set; }
        public virtual DbSet<RenderingType> RenderingType { get; set; }
        public virtual DbSet<Scene> Scene { get; set; }
        public virtual DbSet<SceneRenderingLink> SceneRenderingLink { get; set; }
        public virtual DbSet<Space> Space { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Rendering>(entity =>
            {
                entity.Property(e => e.Id).HasColumnName("id");

                entity.Property(e => e.Datasource)
                    .HasColumnName("datasource")
                    .HasMaxLength(50)
                    .IsUnicode(false);

                entity.Property(e => e.Name)
                    .HasColumnName("name")
                    .HasMaxLength(50)
                    .IsUnicode(false);

                entity.Property(e => e.Renderinglinkid).HasColumnName("renderinglinkid");

                entity.Property(e => e.Renderingtypeid).HasColumnName("renderingtypeid");

                entity.Property(e => e.Spaceid).HasColumnName("spaceid");

                entity.HasOne(d => d.Renderinglink)
                    .WithMany(p => p.Rendering)
                    .HasForeignKey(d => d.Renderinglinkid)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_Rendering_RenderingLink");

                entity.HasOne(d => d.Renderingtype)
                    .WithMany(p => p.Rendering)
                    .HasForeignKey(d => d.Renderingtypeid)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_Rendering_RenderingType");

                entity.HasOne(d => d.Space)
                    .WithMany(p => p.Rendering)
                    .HasForeignKey(d => d.Spaceid)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_Rendering_Space");
            });

            modelBuilder.Entity<RenderingLink>(entity =>
            {
                entity.Property(e => e.Id).HasColumnName("id");

                entity.Property(e => e.Childrenderingid).HasColumnName("childrenderingid");

                entity.Property(e => e.Parentrenderingid).HasColumnName("parentrenderingid");

                entity.HasOne(d => d.Childrendering)
                    .WithMany(p => p.RenderingLinkChildrendering)
                    .HasForeignKey(d => d.Childrenderingid)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_RenderingLink_ChildRendering");

                entity.HasOne(d => d.Parentrendering)
                    .WithMany(p => p.RenderingLinkParentrendering)
                    .HasForeignKey(d => d.Parentrenderingid)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_RenderingLink_ParentRendering");
            });

            modelBuilder.Entity<RenderingType>(entity =>
            {
                entity.Property(e => e.Id).HasColumnName("id");

                entity.Property(e => e.Handler)
                    .HasColumnName("handler")
                    .HasMaxLength(50)
                    .IsUnicode(false);

                entity.Property(e => e.Name)
                    .IsRequired()
                    .HasColumnName("name")
                    .HasMaxLength(50)
                    .IsUnicode(false);
            });

            modelBuilder.Entity<Scene>(entity =>
            {
                entity.Property(e => e.Id).HasColumnName("id");

                entity.Property(e => e.Name)
                    .IsRequired()
                    .HasColumnName("name")
                    .HasMaxLength(50)
                    .IsUnicode(false);
            });

            modelBuilder.Entity<SceneRenderingLink>(entity =>
            {
                entity.HasIndex(e => e.Id)
                    .HasName("IX_SceneRendering");

                entity.Property(e => e.Id).HasColumnName("id");

                entity.Property(e => e.Renderingid).HasColumnName("renderingid");

                entity.Property(e => e.Sceneid).HasColumnName("sceneid");

                entity.HasOne(d => d.Rendering)
                    .WithMany(p => p.SceneRenderingLink)
                    .HasForeignKey(d => d.Renderingid)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_SceneRenderingLink_Rendering");

                entity.HasOne(d => d.Scene)
                    .WithMany(p => p.SceneRenderingLink)
                    .HasForeignKey(d => d.Sceneid)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_SceneRendering_Scene");
            });

            modelBuilder.Entity<Space>(entity =>
            {
                entity.Property(e => e.Id).HasColumnName("id");

                entity.Property(e => e.Description)
                    .HasColumnName("description")
                    .HasMaxLength(50)
                    .IsUnicode(false);

                entity.Property(e => e.X).HasColumnName("x");

                entity.Property(e => e.Y).HasColumnName("y");

                entity.Property(e => e.Z).HasColumnName("z");
            });
        }
    }
}
