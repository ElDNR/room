using System;
using System.Collections.Generic;

namespace room.server.data.Models
{
    public partial class Rendering
    {
        public Rendering()
        {
            RenderingLinkChildrendering = new HashSet<RenderingLink>();
            RenderingLinkParentrendering = new HashSet<RenderingLink>();
            SceneRenderingLink = new HashSet<SceneRenderingLink>();
        }

        public int Id { get; set; }
        public int Renderingtypeid { get; set; }
        public int Spaceid { get; set; }
        public int Colorid { get; set; }
        public int Renderinglinkid { get; set; }
        public string Name { get; set; }
        public string Datasource { get; set; }

        public Color Color { get; set; }
        public RenderingLink Renderinglink { get; set; }
        public RenderingType Renderingtype { get; set; }
        public Space Space { get; set; }
        public ICollection<RenderingLink> RenderingLinkChildrendering { get; set; }
        public ICollection<RenderingLink> RenderingLinkParentrendering { get; set; }
        public ICollection<SceneRenderingLink> SceneRenderingLink { get; set; }
    }
}
