import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { WhereIsGuidoComponent } from './where-is-guido.component';

describe('WhereIsGuidoComponent', () => {
  let component: WhereIsGuidoComponent;
  let fixture: ComponentFixture<WhereIsGuidoComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ WhereIsGuidoComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(WhereIsGuidoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
