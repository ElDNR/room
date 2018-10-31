using System;
using System.Collections.Generic;

namespace room.server.data.Models
{
    public partial class RenderingLink
    {
        public RenderingLink()
        {
            Rendering = new HashSet<Rendering>();
        }

        public int Id { get; set; }
        public int Parentrenderingid { get; set; }
        public int Childrenderingid { get; set; }

        public Rendering Childrendering { get; set; }
        public Rendering Parentrendering { get; set; }
        public ICollection<Rendering> Rendering { get; set; }
    }
}
