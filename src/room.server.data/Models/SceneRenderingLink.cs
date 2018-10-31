using System;
using System.Collections.Generic;

namespace room.server.data.Models
{
    public partial class SceneRenderingLink
    {
        public int Id { get; set; }
        public int Sceneid { get; set; }
        public int Renderingid { get; set; }

        public Rendering Rendering { get; set; }
        public Scene Scene { get; set; }
    }
}
