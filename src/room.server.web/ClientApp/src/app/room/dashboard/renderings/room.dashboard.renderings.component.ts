import { Component, Inject, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';
import { RoomDashboardAuthenticator } from '../room.dashboard.authenticator';

@Component({
  selector: 'app-roomdashboardrenderings',
  templateUrl: './room.dashboard.renderings.component.html'
})
export class RoomDashboardRenderingsComponent implements OnInit {

  private Router: Router;
  private Http: HttpClient;
  private BaseUrl: string;

  public Renderings = [];
  public ShowNoRenderingsMessage: boolean = false;

  constructor(router: Router, http: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    this.Router = router;
    this.Http = http;
    this.BaseUrl = baseUrl;
  }

  public ngOnInit() {
    var _self = this;

    var authenticator: RoomDashboardAuthenticator = new RoomDashboardAuthenticator(this.Http, this.BaseUrl);
    authenticator.authenticate(function () {
      console.log("RoomDashboardRenderingsComponent authenticated.");

      //Test data.
      _self.Renderings.push({
        'id': 1,
        'name': 'hello',
        'type': 'image'
      }, {
        'id': 2,
        'name': 'world',
        'type': 'square'
      });
    }, function () {
      _self.Router.navigate(['/room']);
    });
  }

}
