using System;
using System.Collections.Generic;

namespace room.server.data.Models
{
    public partial class Scene
    {
        public Scene()
        {
            SceneRenderingLink = new HashSet<SceneRenderingLink>();
        }

        public int Id { get; set; }
        public string Name { get; set; }

        public ICollection<SceneRenderingLink> SceneRenderingLink { get; set; }
    }
}
